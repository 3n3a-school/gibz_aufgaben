from helpers.table import TableConsole
from db.db import DB
from store.customer import Customer

if __name__=="__main__":
    db = DB()
    # tc = TableConsole()
    # tc.print("contact_persons")
    db.update_record("contact_persons", {'name':"bruh1234"}, 1)    