import psycopg2
from db.db import DB

class Customer:
    def __init__(self) -> None:
        db = DB()
        self.cur = db.get_cursor()
    
    def add(self, sql):
        pass
