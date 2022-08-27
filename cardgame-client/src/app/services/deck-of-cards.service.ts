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

  constructor(
    private httpMsgService: HttpMsgService
  ) { }
}
