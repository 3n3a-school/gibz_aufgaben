from db.database import DB
from pathlib import Path
from store.project import Project

def exercise_1():
    """create employees table"""
    db = DB(create_script=Path('employee_table.sql'))
    db.create_table()

def exercise_2():
    """create employees table in 1NF"""
    db = DB(create_script=Path('employee_table_nf1.sql'))
    db.create_table()

def exercise_3():
    """create employees table in 1NF"""
    db = DB(create_script=Path('employee_table_nf2.sql'))
    db.create_table()

def exercise_4():
    """create employees table in 1NF"""
    db = DB(create_script=Path('employee_table_nf3.sql'))
    db.create_table()

def exercise_5():
    """adds employee and project data"""
    db = DB()
    db.execute("INSERT INTO roles (name) VALUES ('Scrum Master')")
    db.execute("INSERT INTO roles (name) VALUES ('Developer')")
    db.execute("INSERT INTO industries (name) VALUES ('Housing')")
    db.execute("INSERT INTO industries (name) VALUES ('IT')")
    db.execute("INSERT INTO employees (name, address, industry_id, manager_id) VALUES ('Adam Smith', 'Street 2', 1, 1)")
    db.execute("INSERT INTO employees (name, address, industry_id, manager_id) VALUES ('John Smith', 'Street 1', 1, 2)")
    db.execute("INSERT INTO employee_role (employee_id, role_id) VALUES (1, 2)")
    db.execute("INSERT INTO employee_role (employee_id, role_id) VALUES (2, 1)")
    db.execute("INSERT INTO contact_persons (name, phone_number) VALUES ('Hans Muster', '01234')")
    db.execute("INSERT INTO contact_persons (name, phone_number) VALUES ('Maria Muster', '012345')")
    db.execute("INSERT INTO projects (name, feedback) VALUES ('CRM Development', '')")
    db.execute("INSERT INTO projects (name, feedback) VALUES ('Rent Dashboard', 'Looking good until now')")
    db.execute("INSERT INTO customers (contact_person_id, address) VALUES (1, 'Willo street 4')")
    db.execute("INSERT INTO customers (contact_person_id, address) VALUES (2, 'Main street 1')")
    db.execute("INSERT INTO customer_project (customer_id, project_id) VALUES (1, 2)")
    db.execute("INSERT INTO customer_project (customer_id, project_id) VALUES (2, 1)")


def exercise_6a():
    """add additional client projects"""
    db = DB()
    db.execute("INSERT INTO projects (name, feedback) VALUES ('Housing Estate Website', '')")
    db.execute("INSERT INTO customer_project (customer_id, project_id) VALUES (1, (SELECT id FROM projects WHERE name = 'Housing Estate Website'))")

def exercise_6b():
    """add additional client feedback"""
    db = DB()
    db.execute("UPDATE projects SET feedback='project is not going good we want more widgets' WHERE name='Housing Estate Website'")

def exercise_7a():
    """add salary for employees"""
    db = DB()
    db.execute("ALTER TABLE employees ADD COLUMN salary INT")

def exercise_7b():
    """add salutation for employees"""
    db = DB()
    db.execute("ALTER TABLE employees ADD COLUMN salutation VARCHAR(20)")

def exercise_8abc():
    """add additional internal projects table"""
    db = DB(create_script=Path('internal_projects.sql'))
    db.create_table()
    db.execute("INSERT INTO internal_projects (name, description, manager_id) VALUES ('Test Project Portal', 'An internal portal for new devs', 1)")

def exercise_9a():
    """with DAO create new project"""
    project = Project()
    project.add_project({'name': 'School Website'})

def exercise_9b():
    """with DAO add project to employee"""
    project = Project()
    project.assign_project(1, 'School Website')

if __name__=="__main__":
    # exercise_1()
    # exercise_2()
    # exercise_3()
    exercise_4()
    exercise_5()
    exercise_6a()
    exercise_6b()
    exercise_7a()
    exercise_7b()
    exercise_8abc()
    exercise_9a()
    exercise_9b()