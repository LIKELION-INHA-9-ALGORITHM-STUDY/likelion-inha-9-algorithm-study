/*입양 시각 구하기(1)*/
SELECT HOUR(DATETIME) AS HOUR, COUNT(DATETIME) FROM ANIMAL_OUTS
GROUP BY HOUR HAVING HOUR >=9 AND HOUR<=19
ORDER BY HOUR