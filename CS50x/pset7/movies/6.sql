SELECT AVG(rating) FROM ratings
JOIN movies ON ratings.movie_id = id
WHERE year = 2012