drop schema public cascade;
create schema public;

CREATE TABLE employees (
    employee_name                 VARCHAR(255),
    employee_role1                VARCHAR(255),
    employee_role2                VARCHAR(255),
    employee_role3                VARCHAR(255),
    employee_address              VARCHAR(255),
    employee_manager              VARCHAR(255),
    industry                      VARCHAR(255),
    employee_id                   INT,
    customer_project1    		  VARCHAR(255),
    customer_project1_feedback    TEXT,
    customer_project2    		  VARCHAR(255),
    customer_project2_feedback    TEXT,
    customer_contact_person       VARCHAR(255),
    phone_number                  INT,
    customer1_address             VARCHAR(255),
    customer2_address             VARCHAR(255)
  );