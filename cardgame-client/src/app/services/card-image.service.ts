import { Injectable } from '@angular/core';
import { Observable, of } from 'rxjs';
import { delay, map, catchError } from 'rxjs/operators';
import { HttpClient, HttpHeaders } from '@angular/common/http';

import { HttpMsgService } from './http-msg.service';

import { CardImage } from '../models/card';
import { CARDIMAGES } from '../shared/cards';

@Injectable({
  providedIn: 'root'
})
export class CardImageService {

  constructor(
    private http: HttpClient,
    private processHttpMsgService: HttpMsgService
    ) { }

    getCustomCardImage(image_src: string): Observable<any> {
      return this.http.get<any>(image_src)
      .pipe(catchError(this.processHttpMsgService.handleError));
    }


}