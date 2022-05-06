import psycopg2
from rich import print

from db.db import DB

class Main:
    def __init__(self) -> None:
        self.connect()

    def connect(self):
        db = DB()
        conn = db.get()
        cursor = conn.cursor()
        self.cursor = cursor

    def execute(self):
        sql = "SELECT * FROM countries LIMIT 5"
        try:
            self.cursor.execute(sql)
            results = self.cursor.fetchall()
            print(results)
        except psycopg2.Error as e:
            pass

if __name__=="__main__":
    app = Main()
    app.execute()