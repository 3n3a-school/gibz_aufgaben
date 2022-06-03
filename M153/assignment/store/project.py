from typing import Dict
from db.database import DB

class Project:
    def __init__(self):
        self.db = DB()

    def __validate_project(self, project: Dict):
        all_required_keys = True if "name" in project.keys() else False
        correct_length = True if len(project['name']) <= 255 else False

        return all_required_keys, correct_length

    def add_project(self, project: Dict):
        all_keys, correct_length = self.__validate_project(project)
        if not all_keys:
            print(f"Not all required keys for project")
            return
        
        if not correct_length:
            print(f"Some values are too long")
            return

        project_name = project["name"]
        project_feedback = project["feedback"] if "feedback" in project.keys() else ""
        project_creation = self.db.insert_record("projects", ["name", "feedback"], [project_name, project_feedback])
        if project_creation:
            print(f"Project {project_name} created successfully")
        else:
            print(f"Project creation failed")

    def assign_project(self, customer, project):
        assigning = self.db.insert_record("customer_project", ["customer_id", "project_id"], [f"(SELECT id FROM customers WHERE id = '{customer}')", f"(SELECT id FROM projects WHERE name = '{project}')"])
        if assigning:
            print(f"Assigned project {project} to {customer} successfully")
        else:
            print(f"Project assigning failed")