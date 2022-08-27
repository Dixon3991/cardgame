import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { DeckOfCardsService } from './services/deck-of-cards.service';
import { SocketioService } from './services/socketio.service';

import { ReactiveFormsModule } from '@angular/forms';
import { GameRoomComponent } from './game-room/game-room.component';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';

@NgModule({
  declarations: [
    AppComponent,
    GameRoomComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ReactiveFormsModule,
    NgbModule
  ],
  providers: [
    SocketioService,
    DeckOfCardsService
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
