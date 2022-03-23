namespace ExamM226A {
    public abstract class Partner
    {
        public ContactPerson ContactPerson {get;set;}

        public Partner(ContactPerson contactPerson, int contribution = -1) {
            ContactPerson = contactPerson;

            if (contribution != -1) {
                SuggestPartnerType(contribution);
            }
        }

        private Partner SuggestPartnerType( int contribution ) {
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