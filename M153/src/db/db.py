import psycopg2


class DB:
    def __init__(self, host="localhost", user="postgres", password="postgres"):
        self.conn = psycopg2.connect(
            dbname="world",
            user=user,
            password=password,
            host=host
        )

    def get(self):
        return self.conn
