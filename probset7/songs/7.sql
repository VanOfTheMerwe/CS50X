--The way I did it:
-- First Query: Get the ID for the artist
--SELECT * FROM artists WHERE name = 'Drake';
-- Second Query: Use the ID
--SELECT AVG(energy) FROM songs WHERE artist_id = '23';

--The way CS50X wants me to do it per one-liner:
SELECT AVG(energy) FROM songs JOIN artists ON songs.artist_id = artists.id WHERE artists.name = 'Drake';
