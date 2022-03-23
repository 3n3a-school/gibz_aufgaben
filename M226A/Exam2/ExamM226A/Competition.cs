using System;
using System.Collections.Generic;

namespace ExamM226A
{
    public abstract class Competition
    {
        private string Title {get;set;}
        private DateTime Date {get;set;}

        public Contestant Winner {get;set;}
        public virtual List<Contestant> Contestants {get;set;}
        public List<Partner> Partners {get;set;}

        public Competition(string title, DateTime date = new DateTime()) {
            Title = title;
            Date = date;
        }

        public virtual void AddContestant(Contestant contestant)
        {
            Contestants.Add(contestant);
        }

        public bool SetWinner(Contestant contestant)
        {
            if (contestant != null && Contestants.Contains(contestant))
            {
                Winner = contestant;
                return true;
            } else {
                return false;
            }
        }
    }
}