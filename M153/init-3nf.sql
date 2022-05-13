CREATE TABLE roles (
	id SERIAL PRIMARY KEY,
	name VARCHAR(255)
);

CREATE TABLE contact_persons (
	id SERIAL PRIMARY KEY,
	name VARCHAR(255),
	role_id INT references roles(id)
);

CREATE TABLE industries (
	id SERIAL PRIMARY KEY,
	name VARCHAR(255)
);

CREATE TABLE customers (
	id	SERIAL PRIMARY KEY,
	name VARCHAR(255),
	industry_id INT references industries(id),
	contact_person_id INT references contact_persons(id),
	phone_number VARCHAR(12),
	address VARCHAR(255),
	city VARCHAR(255),
	zip	VARCHAR(5)
);

CREATE TABLE projects (
	id  SERIAL PRIMARY KEY,
	feedback TEXT,
	customer_id INT references customers(id)
);