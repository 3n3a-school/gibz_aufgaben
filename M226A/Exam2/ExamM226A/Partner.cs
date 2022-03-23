namespace ExamM226A {
    public abstract class Partner
    {
        public ContactPerson ContactPerson {get;set;}

        public Partner(ContactPerson contactPerson, int contribution = null) {
            ContactPerson = contactPerson;

            if (contribution != null) {
                SuggestPartnerType(contribution);
            }
        }

        private Partner SuggestPartnerType( int contribution ) {
            switch (contribution)
            {
                case contribution > 25000:
                    return new PlatinumPartner(ContactPerson, contribution);
                    break;
                case contribution > 0:
                    return new GoldPartner(ContactPerson, contribution);
                    break;
                default:
                    return new MediaPartner(ContactPerson);
                    break;
            }
        }
    }
}