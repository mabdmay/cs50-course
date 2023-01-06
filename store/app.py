from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

app = Flas(__name__)

db = SQL("sqlite:///store.db")

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    books = db.execute("Select * from books")
    return render_template("books.html", books=books)

@app.route("/cart", methods=["GET", "POST"])
def cart():

    if "cart" not in session:
        session["cart"] = []

    if request.method == "POST":
        id = request.form.get("id")
        if id:
            session["cart"].append(id)
        return redirect("/cart")

    books = db.execute("Select * from books where id in (?)", session["cart"])
    return return_template("cart.html", books=books)

