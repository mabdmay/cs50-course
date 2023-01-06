import os

from cs50 import SQL

db = SQL("sqlite:///birthdays.db")

birthdays = db.execute("select name, month, day from birthdays")

print(birthdays)