drop schema public cascade;
create schema public;


CREATE TABLE contact_persons (
  id SERIAL PRIMARY KEY,
  name VARCHAR(255),
  phone_number VARCHAR(20)
);

CREATE TABLE industries (
  id SERIAL PRIMARY KEY,
  name VARCHAR(255)
);

CREATE TABLE customers (
  id SERIAL PRIMARY KEY,
  contact_person_id INT references contact_persons(id),
  address VARCHAR(255)
);

CREATE TABLE projects (
  id SERIAL PRIMARY KEY,
  name VARCHAR(255),
  feedback TEXT
);

CREATE Table customer_project (
  customer_id INT references customers(id),
  project_id INT references projects(id)
);

CREATE TABLE employees (
  id  SERIAL PRIMARY KEY,
  name VARCHAR(255),
  address VARCHAR(255),
  industry_id INT references industries(id),
  manager_id INT references employees(id)
);

CREATE TABLE roles (
	id SERIAL PRIMARY KEY,
	name VARCHAR(255)
);

CREATE TABLE employee_role (
  employee_id INT references employees(id),
  role_id INT references roles(id)
);

