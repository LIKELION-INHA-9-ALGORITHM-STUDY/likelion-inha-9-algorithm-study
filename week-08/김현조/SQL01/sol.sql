/* SQL문제 1. 최댓값 구하기 */

SELECT DATETIME
FROM ANIMAL_INS
ORDER BY DATETIME DESC 
LIMIT 1 /* 상위 n개만의 data 조회 */