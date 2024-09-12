--The way I did it:
--First Query: Get the artist ID
--SELECT * FROM artists WHERE name = 'Post Malone';
--Second Query: Use the artist ID to get the songs
--SELECT name FROM songs WHERE artist_id = '54';

--The way I was supposed to do it according to CS50X Hints:
SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Post Malone');
