# Whotsapp

Progetto di messaggistica istantanea in C++ sviluppato per scopi didattici.

## Funzionalità
- Gestione Utenti: Registrazione, login e gestione profili.
- Messaggistica: Sistema di chat tra utenti con invio e cancellazione messaggi.
- Notifiche: Gestione dinamica dei messaggi non letti.

## Architettura

Il progetto è diviso in due strati:
- Core Logic: User, Chat, Message e ProgramManager
- UI Layer (CLI): TextUserInterface

Questa struttura divisa in due strati permette una separazione chiara delle responsabilità, migliorando la manutenibilità e la scalabilità del software, quindi la sua possibile espansione. 

La gestione della memoria è effettuata tramite smart pointers.
- Unique pointer: Utilizzato dal ProgramManager per la proprietà esclusiva degli utenti, garantendo la loro distruzione alla chiusura del programma.
- Shared pointer: Utilizzato per le chat condivise, permettendo la loro eliminazione solo quando entrambi i partecipanti hanno rimosso il riferimento.
Eliminiamo il rischio di memory leak

ProgramManager funziona come un controller che gestisce tutte le operazioni del programma, tra cui il registrazione degli utenti e la gestione delle chat.

Il software implementa anche la gestione degli errori tramite eccezioni personalizzate.

Infine viene utilizzato lo unit testing per verificare la correttezza delle funzioni, sviluppati con Google Test.
