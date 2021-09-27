/* 동명 동물 찾기 */
SELECT NAME, COUNT(NAME) FROM ANIMAL_INS
GROUP BY NAME HAVING COUNT(NAME) >= 2
ORDER BY NAME
/* having 절은 집계한 내용을 가지고 조견 비교를 할 때 사용*/