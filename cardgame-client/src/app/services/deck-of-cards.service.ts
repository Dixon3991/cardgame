import { Injectable } from '@angular/core';
import { Observable, of } from 'rxjs';
import { delay, map, catchError } from 'rxjs/operators';
import { HttpClient, HttpHeaders } from '@angular/common/http';

import { DeckOfCardsAPI } from '../shared/baseurl';
import { HttpMsgService } from './http-msg.service';

import { CARDS } from '../shared/cards';
import { Card } from '../models/card';
import { CardDeck } from '../models/card-deck';


@Injectable({
  providedIn: 'root'
})
export class DeckOfCardsService {

  constructor(private http: HttpClient,
    private processHttpMsgService: HttpMsgService) { }
    // Get a New, Shuffled Deck. Add Quanitity of decks. default is 1 deck
    getNewShuffledDeck(deck_count: number = 1): Observable<CardDeck[]> {
      return this.http.get<CardDeck[]>(`${DeckOfCardsAPI}/new/shuffle/?deck_count=${String(deck_count)}`)
      .pipe(catchError(this.processHttpMsgService.handleError));
    }


    // Reshuffle the cards (Choice between all cards in deck or only the remianing cards)
    reShuffleCards(deck_id: string, remaining: boolean = false): Observable<CardDeck> {
      let reShuffleURL: string;
      if (remaining == true) {
        reShuffleURL = `${DeckOfCardsAPI}/${deck_id}/shuffle/?remaining=true`;

      } else {
        reShuffleURL = `${DeckOfCardsAPI}/${deck_id}/shuffle/`;
      }
      return this.http.get<CardDeck>(reShuffleURL)
      .pipe(catchError(this.processHttpMsgService.handleError));
    }

    // Get a New, Unshuffled Deck of Cards, optional Jokers. Default is no Jokers (false)
    getNewDeck(jokers_enabled: boolean = false): Observable<CardDeck> {
      let newDeckURL: string;
      if (jokers_enabled) {
        newDeckURL = `${DeckOfCardsAPI}/new/jokers_enabled=true`;
      } else {
        newDeckURL = `${DeckOfCardsAPI}/new/`;
      }
      return this.http.get<CardDeck>(newDeckURL)
      .pipe(catchError(this.processHttpMsgService.handleError));
    }

    // Draw Cards from the deck
    drawACard(deck_id: string, draw_count: number): Observable<CardDeck> {
      return this.http.get<CardDeck>(`DeckOfCardsAPI/${deck_id}/draw/?count=${String(draw_count)}`)
      .pipe(catchError(this.processHttpMsgService.handleError));
    }

    // Add Cards to Pile. Just give the pile a name and add a drawn card, to the pile
    // NOTE - Does not work with multiple decks
    addCardsToPile(deck_id: string, pile_name: string, added_cards: string): Observable<CardDeck> {
      return this.http.get<CardDeck>(`DeckOfCardsAPI/${deck_id}/pile/${pile_name}/add/?cards=${added_cards}`)
      .pipe(catchError(this.processHttpMsgService.handleError));
    }

    // Return Specific cards to Pile
    returnCardsToPile(deck_id: string, pile_name: string, added_cards: string): Observable<CardDeck> {
      return this.http.get<CardDeck>(`DeckOfCardsAPI/${deck_id}/pile/${pile_name}/return/?cards=${added_cards}`)
      .pipe(catchError(this.processHttpMsgService.handleError));
    }

    // Return All Cards to Pile
    returnAllCardsToPile(deck_id: string, pile_name: string): Observable<CardDeck> {
      return this.http.get<CardDeck>(`DeckOfCardsAPI/${deck_id}/pile/${pile_name}/return`)
      .pipe(catchError(this.processHttpMsgService.handleError));
    }

    // List all cards in pile
    listCardsInPile(deck_id: string, pile_name: string): Observable<CardDeck> {
      return this.http.get<CardDeck>(`DeckOfCardsAPI/${deck_id}/pile/${pile_name}/list/`)
      .pipe(catchError(this.processHttpMsgService.handleError));
    }
  
}
