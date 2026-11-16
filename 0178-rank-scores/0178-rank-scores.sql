# Write your MySQL query statement below
-- SELECT 
--     s1.score,
--     (
--         SELECT COUNT(DISTINCT s2.score)
--         FROM Scores s2
--         WHERE s2.score > s1.score
--     ) + 1 AS `rank` FROM Scores s1 ORDER BY score DESC;

-- with score_rank as (
--     select score,Dense_Rank() over(
--         order by score desc
--     )as rn from Score
-- )
-- select score, rn as rank from score_rank;


    select score,Dense_Rank() over(
        order by score desc
    ) `rank` from Scores
