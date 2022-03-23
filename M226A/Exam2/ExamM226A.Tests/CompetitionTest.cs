using Microsoft.VisualStudio.TestTools.UnitTesting;

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
    }
}