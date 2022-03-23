using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;

namespace ExamM226A.Tests
{
    [TestClass]
    public class CompetitionTest
    {

        [TestMethod]
        public void SetParticipatingPersonAsWinnerTest()
        {
            // Arrange
            Competition competition = new IndividualCompetition("Test Competition");
            Contestant contestant = new IndividualContestant();
            competition.AddContestant(contestant);

            // Act
            bool isValidWinner = competition.SetWinner(contestant);

            // Assert
            Assert.IsTrue(isValidWinner);
            Assert.AreEqual(contestant, competition.Winner);
        }

        [TestMethod]
        public void SetNonParticipatingPersonAsWinnerTest()
        {
            // Arrange
            Competition competition = new IndividualCompetition("Test Competition");
            Contestant contestant = new IndividualContestant();

            // Act
            bool isValidWinner = competition.SetWinner(contestant);

            // Assert
            Assert.IsFalse(isValidWinner);
            Assert.IsNull(competition.Winner);
        }
        
        [TestMethod]
        public void SetNonParticipatingTeamAsWinnerTest()
        {
            // Arrange
            Competition competition = new TeamComptetition("Test Competition", 4);
            Contestant contestant = new Team();

            // Act
            bool isValidWinner = competition.SetWinner(contestant);

            // Assert
            Assert.IsFalse(isValidWinner);
            Assert.IsNull(competition.Winner);
        }
        
        [TestMethod]
        public void AutoSuggestPlatinSponsorType()
        {
            // Arrange
            ContactPerson contactPerson = new ContactPerson();
            Competition competition = new TeamComptetition("Test Competition", 4);
            Partner partner = new Partner(contactPerson, 25001);

            // Act
            dynamic returnedPartner = partner.SuggestedPartner;
            Type partnerType = returnedPartner.GetType();

            // Assert
            Assert.AreEqual(typeof(PlatinumPartner), partnerType);
        }

        [TestMethod]
        public void TestTeamSizeForTeam() {
            // Arrange
            Competition competition = new TeamComptetition("Test Competition", 4);
            Team team = new Team();

            team.AddAthlete(new IndividualContestant());
            team.AddAthlete(new IndividualContestant());
            team.AddAthlete(new IndividualContestant());
            competition.AddContestant(team);

            // Act
            bool isTeamCorrectsize = team.IsCorrectTeamSize(4, 2);

            //Assert
            Assert.IsTrue(isTeamCorrectsize);

        }
    }
}