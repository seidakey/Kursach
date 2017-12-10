DROP TABLE IF EXISTS tree;
DROP TABLE IF EXISTS bird;
DROP TABLE IF EXISTS dictionary;
DROP TABLE IF EXISTS dictionary_field;

CREATE TABLE tree (
    id              INTEGER PRIMARY KEY AUTOINCREMENT,
    birthdate       DATE,
    height          DOUBLE(16,8),
    history         TEXT
);

INSERT INTO TREE VALUES (0, '1 jan 1970', 200.1, 'It was born in Greenland 47 year ago');
INSERT INTO TREE VALUES (1, '27 mar 1998', 200.1, 'It was born in Greenland 19 year ago');
INSERT INTO TREE VALUES (2, '1 jan 1970', 200.1, 'It was born in Greenland 47 year ago');
INSERT INTO TREE VALUES (3, '1 jan 1970', 200.1, 'It was born in Greenland 47 year ago');
INSERT INTO TREE VALUES (4, '1 jan 1970', 200.1, 'It was born in Greenland 47 year ago');

CREATE TABLE bird (
    id              INTEGER PRIMARY KEY AUTOINCREMENT,
    birthdate       DATE,
    mass            DOUBLE(16,8),
    history         TEXT,
    tree_id         INTEGER,
	FOREIGN KEY(tree_id) REFERENCES tree(id)
);

INSERT INTO BIRD VALUES (0, '1970-1-1', 200.1, 'It was born in Greenland 47 year ago', 0);
INSERT INTO BIRD VALUES (1, '27 mar 1998', 200.1, 'It was born in Greenland 19 year ago', 1);
INSERT INTO BIRD VALUES (2, '1 jan 1970', 200.1, 'It was born in Greenland 47 year ago', 2);
INSERT INTO BIRD VALUES (3, '1 jan 1970', 200.1, 'It was born in Greenland 47 year ago', 3);
insert into bird (birthdate,mass,history) values('2017-11-19',123,'asfd');

CREATE TABLE dictionary (
    id              INTEGER PRIMARY KEY AUTOINCREMENT,
    name            CHAR(40)
);

INSERT INTO dictionary VALUES (0, 'tree');
INSERT INTO dictionary VALUES (1, 'bird');

CREATE TABLE dictionary_field (
    id              INTEGER PRIMARY KEY AUTOINCREMENT,
    dict_id         INTEGER REFERENCES dictionary(id),
	app_name		CHAR(40),
    field_name      CHAR(40),
    field_type		CHAR(40),
    form_type       CHAR(20)
);

INSERT INTO dictionary_field VALUES (0, 0, 'День рождения', 'birthdate', 'text', 'Calendar');
INSERT INTO dictionary_field VALUES (1, 0, 'Вес', 'height', 'other', 'FloatLine');
INSERT INTO dictionary_field VALUES (2, 0, 'История', 'history', 'text', 'TextBlock');
INSERT INTO dictionary_field VALUES (3, 1, 'День рождения', 'birthdate', 'text', 'Calendar');
INSERT INTO dictionary_field VALUES (4, 1, 'Вес', 'mass', 'other', 'FloatLine' );
INSERT INTO dictionary_field VALUES (5, 1, 'История', 'history', 'text', 'TextBlock');
INSERT INTO dictionary_field VALUES (6, 1, 'Номер дерева', 'tree_id', 'other', 'IntegerLine');
