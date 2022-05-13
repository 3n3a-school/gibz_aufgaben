from pathlib import Path
import psycopg2
import os


class DB:
    def __init__(self, host=os.environ.get("DB_HOST"), user=os.environ.get("DB_USER"), password=os.environ.get("DB_PASS")):
        self.conn = psycopg2.connect(
            dbname=os.environ.get("DB_NAME"),
            user=user,
            password=password,
            host=host
        )
        self.connect()

    def connect(self):
        cursor = self.conn.cursor()
        self.cursor = cursor

    def create_table(self):
        sql = ""
        with open(Path(__file__, 'init-3nf.sql'), 'r') as f:
            sql = f.read()
        self.cur.execute(sql)
        self.cur.commit()