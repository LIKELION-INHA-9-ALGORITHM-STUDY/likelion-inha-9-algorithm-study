/* SQL문제 5. 상위 1개 레코드 */

SELECT NAME
FROM ANIMAL_INS
ORDER BY DATETIME
LIMIT 1 /* 상위 n개만의 data 조회 */