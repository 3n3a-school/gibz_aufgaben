import enum
import psycopg2
from rich.console import Console
from rich.table import Table

from db.db import DB

class Main:
    def __init__(self) -> None:
        self.console = Console()
        db = DB()
        self.cur = db.get_cursor()

    def execute(self, sql):
        try:
            self.cur.execute(sql)
            results = self.cur.fetchall()
            return results
        except psycopg2.Error as e:
            pass

    def print_table(self, table_name, data):
        """prints a given sql table's data as a beautiful table in your terminal"""
        header = self.execute("SELECT column_name FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '{}';".format(table_name))

        table = Table(show_header=True, header_style="bold magenta")

        data_dict = list()

        for col in header:
            table.add_column(list(col)[0])

        for j, row in enumerate(data):
            data_dict.append(dict())
            for i, col in enumerate(header):
                data_dict[j][str(list(row)[i])] = list()
        
        for row in data_dict:
            table.add_row(
                *row
            )
        
        self.console.print(table)

if __name__=="__main__":
    app = Main()
    countries = app.execute("SELECT * FROM countries LIMIT 5")
    app.print_table("countries", countries)