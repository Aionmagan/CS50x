SELECT title, rating FROM ratings
JOIN movies on ratings.movie_id = id
WHERE year = 2010
ORDER BY rating DESC, title ASC