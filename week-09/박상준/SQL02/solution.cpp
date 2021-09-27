SELECT TRIM(LEADING  '0' FROM substring(DATETIME, 12, 2)), COUNT(substring(DATETIME, 12, 2)) FROM ANIMAL_OUTS
WHERE substring(DATETIME, 12, 2) >= '09' and substring(DATETIME, 12, 2) <= '19'
GROUP BY substring(DATETIME, 12, 2)
ORDER BY substring(DATETIME, 12, 2)