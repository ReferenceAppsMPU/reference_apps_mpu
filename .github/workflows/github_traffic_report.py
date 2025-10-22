import json
import os
import subprocess
from datetime import datetime, timedelta

# File paths
file_path = "traffic-data.json"
history_path = "traffic-history.json"
report_path = "quarterly_traffic_report.txt"

# Load today's fetched traffic data
with open(file_path, "r") as f:
    new_data = json.load(f)

# GitHub API returns in the "views" key
new_views = new_data.get("views", new_data)

# Load existing history if available
if os.path.exists(history_path):
    with open(history_path, "r") as f:
        history = json.load(f)
else:
    history = {"views": []}

# Merge new records into history (avoid duplicates)
existing_dates = {r["timestamp"][:10] for r in history["views"]}
for record in new_views:
    ts = record["timestamp"][:10]
    if ts not in existing_dates:
        history["views"].append(record)

# Keep only the last 90 days
history["views"].sort(key=lambda x: x["timestamp"])
cutoff_date = datetime.now() - timedelta(days=90)
history["views"] = [
    r for r in history["views"] if datetime.strptime(r["timestamp"][:10], "%Y-%m-%d") >= cutoff_date
]

# Save updated history
with open(history_path, "w") as f:
    json.dump(history, f, indent=2)

# --- Generate quarterly summary ---
total_views = sum(r["count"] for r in history["views"])
unique_visitors = sum(r["uniques"] for r in history["views"])

start_date = datetime.strptime(history["views"][0]["timestamp"][:10], "%Y-%m-%d")
end_date = datetime.strptime(history["views"][-1]["timestamp"][:10], "%Y-%m-%d")
days_tracked = (end_date - start_date).days + 1
avg_views_per_day = total_views / days_tracked if days_tracked else 0

report = f"""
📊 GitHub Quarterly Traffic Report
----------------------------------
Period: {start_date.date()} → {end_date.date()}
Days Tracked: {days_tracked}
Total Views: {total_views}
Unique Visitors: {unique_visitors}
Average Views/Day: {avg_views_per_day:.2f}
Projected Quarterly Views (90 days): {avg_views_per_day * 90:.0f}

Generated on: {datetime.now().strftime("%Y-%m-%d %H:%M:%S")}
"""

# Save text report
with open(report_path, "w") as f:
    f.write(report)

print(report)

# Commit & push updated history + report
subprocess.run(["git", "config", "user.name", "github-actions[bot]"])
subprocess.run(["git", "config", "user.email", "github-actions[bot]@users.noreply.github.com"])
subprocess.run(["git", "add", history_path, report_path])
subprocess.run(["git", "commit", "-m", "Updated GitHub traffic history and quarterly report"])
subprocess.run(["git", "push"])
