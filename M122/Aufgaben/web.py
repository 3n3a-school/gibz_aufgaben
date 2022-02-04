import requests
import feedparser
from rich.table import Table
from rich.console import Console
from rich.markdown import Markdown

console = Console()

def get_public_ip():
    r = requests.get('https://ifconfig.me')
    public_ip = r.text
    return public_ip

def get_news(url="https://www.theguardian.com/world/rss"):
    NewsFeed = feedparser.parse(url)
    return NewsFeed.entries

def print_news(news_entries):
    table = Table(show_header=True, header_style="bold magenta", show_lines=True)
    table.add_column("Title", style="red")
    table.add_column("Date")
    table.add_column("Link")

    for n in news_entries:
        table.add_row(
            n.title,
            n.published,
            n.link,
        )
    
    console.print(Markdown("# Blick"))
    console.print(table)

def print_menu(menues):
    print(" -- WebTool 1.0 --")
    for menu in menues:
        print("{}: {}".format(menu["id"], menu["name"]))

def print_public_ip():
    print("Public IP-Address: {}".format(get_public_ip()))

def get_latest_news():
    news_feed = get_news("https://www.blick.ch/news/rss.xml")
    print_news(news_feed)

def menu_switch(menu_item):
    return {
        1: lambda: print_public_ip(),
        2: lambda: get_latest_news(),
    }.get(menu_item)()

def main():
    menues = [
        {"id": 1, "name": "Print Public IP Address"},
        {"id": 2, "name": "Get the latest News (Blick)"},
    ]
    print_menu(menues)
    chosen_menu_item = int(input("Enter the menu item: "))
    menu_switch(chosen_menu_item)


if __name__=="__main__":
    main()