package tvserie;

// Un episodio di una serie televisiva è caratterizzato da un titolo, una trama e un riferimento al prossimo episodio della serie. 
// Si scriva una classe Episode per memorizzare i dati descritti sopra. Dotare la classe Episode dei metodi toString e equals:
// due episodi sono uguali se hanno lo stesso titolo (a meno di maiuscole e minuscole) e se hanno anche i loro episodi successivi sono uguali.

public class Episode {

    private String title;
    private String plot;
    private Episode nextEpisode;

    // Constructors

    public Episode() {
        this.title = "";
        this.plot = "";
        this.nextEpisode = null;
    }

    public Episode(String title, String plot, Episode nextEp) {
        this.title = title;
        this.plot = plot;
        this.nextEpisode = nextEp;
    }

    public Episode(String title, String plot) {
        this.title = title;
        this.plot = plot;
        this.nextEpisode = null;
    }

    // Getters
    public String getTitle() {
        return this.title;
    }

    public String getPlot() {
        return this.plot;
    }

    public Episode getNextEpisode() {
        return this.nextEpisode;
    }

    // Setters
    public void setTitle(String title) {
        this.title = title;
    }

    public void setPlot(String plot) {
        this.plot = plot;
    }

    public void setNextEpisode(Episode nextEp) {
        this.nextEpisode = nextEp;
    }

    // Overloading of standard operators

    public String toString() {

        String stringifiedEpisode = new String("{ ");

        stringifiedEpisode += "title: " + this.title + ", ";
        stringifiedEpisode += "plot: " + this.plot;
        if (this.nextEpisode != null)
            stringifiedEpisode += ", nextEpisode: " + this.nextEpisode.getTitle();
        stringifiedEpisode += " }";

        return stringifiedEpisode;

    }

    public boolean equals(Episode episode) {

        if (this.title.toLowerCase().equals(episode.title.toString().toLowerCase())) {
            Episode cursor1 = this.nextEpisode;
            Episode cursor2 = episode.nextEpisode;

            while (cursor1 != null && cursor2 != null) {
                if (!cursor1.title.toLowerCase().equals(cursor2.title.toString().toLowerCase()))
                    return false;

                cursor1 = cursor1.nextEpisode;
                cursor2 = cursor2.nextEpisode;
            }

            // the lists have different lengths
            if (cursor1 == null && cursor2 == null)
                return true;
            else
                return false;

        } else
            return false;

    }

}
