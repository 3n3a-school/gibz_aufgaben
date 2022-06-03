import psycopg2
from db.db import DB

class Customer:
    def __init__(self) -> None:
        self.db = DB()
    
    def add(self, ):
