# Write your MySQL query statement below
WITH NumberedStadia AS (
    SELECT 
        id, 
        visit_date, 
        people,
        id - ROW_NUMBER() OVER(ORDER BY id) AS grp
    FROM Stadium
    WHERE people >= 100
),
GroupCounts AS (
    SELECT grp
    FROM NumberedStadia
    GROUP BY grp
    HAVING COUNT(id) >= 3
)
SELECT id, visit_date, people
FROM NumberedStadia
WHERE grp IN (SELECT grp FROM GroupCounts)
ORDER BY visit_date;