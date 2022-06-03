CREATE TABLE internal_projects (
    name                  VARCHAR(255),
    description           VARCHAR(300),
    manager_id             INT references employees(id)
  );