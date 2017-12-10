DROP TABLE IF EXISTS TEST_CONSPECTUS1;
DROP TABLE IF EXISTS TEST_CONSPECTUS2;
DROP TABLE IF EXISTS CONSPECTUS;

CREATE TABLE TEST_CONSPECTUS1 (
	id				INTEGER PRIMARY KEY AUTOINCREMENT,
	question		CHAR(255) NOT NULL,
	answer			TEXT NOT NULL
);

INSERT INTO TEST_CONSPECTUS1
	VALUES (1, '1st question very long long long long long long long', 'answer1');
INSERT INTO TEST_CONSPECTUS1
	VALUES (10, '2nd question', 'aswer to question 2');

CREATE TABLE TEST_CONSPECTUS2 (
	id				INTEGER PRIMARY KEY AUTOINCREMENT,
	question		CHAR(255) NOT NULL,
	answer			TEXT NOT NULL
);

INSERT INTO TEST_CONSPECTUS2
	VALUES (1, 'Вопрос 1', 'Здесь ответ ввиде форматированного текста');
INSERT INTO TEST_CONSPECTUS2
	VALUES (10, 'Вопрос 2', 'Здесь ответ ввиде форматированного текста');

CREATE TABLE CONSPECTUS (
	id				INTEGER PRIMARY KEY AUTOINCREMENT,
	title			CHAR(255),
	table_name		CHAR(255)
);

INSERT INTO CONSPECTUS
	(table_name,title)
	VALUES('TEST_CONSPECTUS1', 'Линейная алгебра');
INSERT INTO CONSPECTUS
	(table_name,title)
	VALUES('TEST_CONSPECTUS2', 'Математический анализ');

