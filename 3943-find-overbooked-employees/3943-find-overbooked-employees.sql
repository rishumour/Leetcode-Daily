# Write your MySQL query statement below
WITH WeeklyHours AS (
    SELECT 
        employee_id, 
        DATE_SUB(meeting_date, INTERVAL WEEKDAY(meeting_date) DAY) AS week_start,
        SUM(duration_hours) AS total_hours
    FROM meetings
    GROUP BY 
        employee_id, 
        DATE_SUB(meeting_date, INTERVAL WEEKDAY(meeting_date) DAY)
    HAVING SUM(duration_hours) > 20
)
SELECT 
    e.employee_id, 
    e.employee_name, 
    e.department, 
    COUNT(w.week_start) AS meeting_heavy_weeks
FROM WeeklyHours w
JOIN employees e ON w.employee_id = e.employee_id
GROUP BY 
    e.employee_id, 
    e.employee_name, 
    e.department
HAVING COUNT(w.week_start) >= 2
ORDER BY 
    meeting_heavy_weeks DESC, 
    e.employee_name ASC;