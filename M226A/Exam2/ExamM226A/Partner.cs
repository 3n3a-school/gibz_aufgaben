using System;

namespace ExamM226A {
    public class Partner
    {
        public ContactPerson ContactPerson {get;set;}

        public object SuggestedPartner {get;set;}
        
        public Partner(ContactPerson contactPerson, int contribution = -1) {
            ContactPerson = contactPerson;

            if (contribution != -1) {
                SuggestedPartner = SuggestPartnerType(contribution);
            }
        }

        private dynamic SuggestPartnerType( int contribution ) {
            if (contribution > 25000) {
                return new PlatinumPartner(ContactPerson, contribution);
            } else if (contribution > 0 ) {
                return new GoldPartner(ContactPerson, contribution);
            } else {
                return new MediaPartner(ContactPerson);
            }
        }
    }
}