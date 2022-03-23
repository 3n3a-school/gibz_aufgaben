using System;
using System.Collections.Generic;

namespace ExamM226A
{
    public abstract class Competition
    {
        private string Title {get;set;}
        private DateTime Date {get;set;}
        public Contestant Winner {get;set;}
        public virtual List<T> Contestants {get;set;}
        public List<Partner> Partners {get;set;}

        public Competition(string title) {
            Title = title;

        }

        public virtual void AddContestant(Contestant contestant)
        {
            Contestants.Add(contestant);
        }

        public bool SetWinner(Contestant contestant)
        {
            Winner = contestant;

            if (Winner != null)
            {
                return true;
            } else {
                return false;
            }
        }
    }
}