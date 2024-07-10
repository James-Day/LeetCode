SELECT Weather.id
FROM Weather
    JOIN Weather as Weather2 ON Weather.recordDate = Weather2.recordDate + 1
WHERE Weather.temperature > Weather2.temperature
