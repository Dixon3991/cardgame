import { Component, OnInit } from '@angular/core';
import { FormBuilder } from '@angular/forms';
import { Player } from '../models/player';
import { SENDER } from '../shared/players';
import { SocketioService } from '../services/socketio.service';

@Component({
  selector: 'app-game-room',
  templateUrl: './game-room.component.html',
  styleUrls: ['./game-room.component.scss']
})
export class GameRoomComponent implements OnInit {

  CHAT_ROOM = "test1room";

  messages = [];

  tokenForm = this.formBuilder.group({
    token: '',
  });

  messageForm = this.formBuilder.group({
    message: '',
  });

  constructor(private socketService: SocketioService, private formBuilder: FormBuilder) {}

  ngOnInit() {
  }

  submitToken() {
    const token = this.tokenForm?.get('token').value;
    if (token) {
      this.socketService.setupSocketConnection(token);
      this.socketService.subscribeToMessages((err, data) => {
        console.log("NEW MESSAGE ", data);
        this.messages = [...this.messages, data];
      });
    }
  }

  submitMessage() {
    const message = this.messageForm.get('message').value;
    if (message) {
      this.socketService.sendMessage({message, roomName: this.CHAT_ROOM}, cb => {
        console.log("ACKNOWLEDGEMENT ", cb);
      });
      this.messages = [
        ...this.messages,
        {
          message,
          ...SENDER,
        },
      ];
      // clear the input after the message is sent
      this.messageForm.reset();
    }
  }
  
  ngOnDestroy() {
    this.socketService.disconnect();
  }
}

}
