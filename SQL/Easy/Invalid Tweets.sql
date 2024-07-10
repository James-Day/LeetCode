--length(string) gives the byte count, char_length(string) gives the actual character count
SELECT tweet_id
FROM Tweets
WHERE char_length(content) > 15;