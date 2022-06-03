from rich.console import Console
from rich.table import Table

from db.db import DB

class TableConsole:
    def __init__(self) -> None:
        self.console = Console()
        self.db = DB()

    def print(self, table_name):
        """prints a given sql table's data as a beautiful table in your terminal"""

        data = self.db.get_record(table_name)
        header = self.db.execute("SELECT column_name FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '{}';".format(table_name))

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