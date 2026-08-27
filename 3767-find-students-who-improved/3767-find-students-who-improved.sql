# Write your MySQL query statement below
WITH ScoreRanks AS (
    SELECT 
        student_id, 
        subject, 
        score,
        ROW_NUMBER() OVER(PARTITION BY student_id, subject ORDER BY exam_date ASC) AS rn_asc,
        ROW_NUMBER() OVER(PARTITION BY student_id, subject ORDER BY exam_date DESC) AS rn_desc
    FROM Scores
)
SELECT 
    student_id, 
    subject,
    MAX(CASE WHEN rn_asc = 1 THEN score END) AS first_score,
    MAX(CASE WHEN rn_desc = 1 THEN score END) AS latest_score
FROM ScoreRanks
GROUP BY student_id, subject
HAVING MAX(CASE WHEN rn_desc = 1 THEN score END) > MAX(CASE WHEN rn_asc = 1 THEN score END)
ORDER BY student_id ASC, subject ASC;