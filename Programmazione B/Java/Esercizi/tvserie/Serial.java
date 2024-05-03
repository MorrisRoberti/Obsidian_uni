package tvserie;

// Una serie televisiva è caratterizzata da un titolo e un episodio iniziale. 
// Scrivere una classe Serial le cui istanze rappresentano serie televisive, dotata dei metodi toString 
// (che deve stampare le informazioni su tutti gli episodi della serie) e equals, assumendo che due serie sono uguali
// se hanno lo stesso titolo (a meno di maiuscole e minuscole) e se anche i loro episodi iniziali sono uguali. 
// Scrivere un programma che crea alcuni oggetti di tipo Episode (collegandoli opportunamente) e di tipo Serial, 
// e verifica che i metodi toString e equals si comportino come atteso.

public class Serial {

    private String title;
    private Episode pilotEpisode;

    // Constructors
    public Serial() {
        this.title = "";
        this.pilotEpisode = new Episode();
    }

    public Serial(String title, Episode pilot) {
        this.title = title;
        this.pilotEpisode = pilot;
    }

    // Getters
    public String getTitle() {
        return this.title;
    }

    public Episode getPilot() {
        return this.pilotEpisode;
    }

    // Setters
    public void setTitle(String title) {
        this.title = title;
    }

    public void setPilot(Episode pilot) {
        this.pilotEpisode = pilot;
    }

    // Overloading of standard operators
    public String toString() {

        String stringigiedSerie = new String("{");
        stringigiedSerie += "seriesTitle: " + this.title + ", ";
        stringigiedSerie += "episodes: [";

        Episode cursor = this.pilotEpisode;
        while (cursor != null) {

            stringigiedSerie += cursor.toString();
            if (cursor.getNextEpisode() != null)
                stringigiedSerie += ", ";

            cursor = cursor.getNextEpisode();
        }

        stringigiedSerie += "] }";
        return stringigiedSerie;

    }

    public boolean equals(Serial serie) {
        if (this.title.equals(serie.title))
            if (this.pilotEpisode.equals(serie.pilotEpisode))
                return true;
        return false;
    }

    // Methods

    /**
     * Adds a new episode in the tail of the queue
     * 
     * @param newEpisode
     */
    public void addEpisode(Episode newEpisode) {
        Episode cursor = this.pilotEpisode;

        // i make the cursor go to the last episode
        while (cursor.getNextEpisode() != null)
            cursor = cursor.getNextEpisode();

        cursor.setNextEpisode(newEpisode);

    }

    public static void main(String[] args) {

        Episode pilot = new Episode("first episode", "plot");
        Episode episode2 = new Episode("second episode", "plot 2");

        Serial serie = new Serial("series title", pilot);

        // System.out.println(serie);

        // serie.addEpisode(episode2);

        // System.out.println(serie);

        Serial serie2 = new Serial("series title", pilot);
        serie2.addEpisode(episode2);

        System.out.println(serie);
        System.out.println(serie2);

        System.out.println(serie.equals(serie2)); // true

        serie2.setTitle("series title different");

        System.out.println(serie.equals(serie2)); // false

    }
}
