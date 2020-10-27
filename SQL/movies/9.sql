SELECT DISTINCT name FROM people JOIN movies ON stars.movie_id = movies.id JOIN stars ON stars.person_id = people.id WHERE year = 2004 ORDER BY birth;