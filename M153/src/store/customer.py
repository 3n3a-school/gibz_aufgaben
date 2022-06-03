import psycopg2
from db.db import DB

class Customer:
    def __init__(self) -> None:
        self.db = DB()
    
    def add(self, customer):
        return self.db.insert_record("customers", customer)

    def getall(self):
        return self.db.get_record("contact_persons")