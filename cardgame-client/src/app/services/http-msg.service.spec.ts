import { TestBed } from '@angular/core/testing';

import { HttpMsgService } from './http-msg.service';

describe('HttpMsgService', () => {
  let service: HttpMsgService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(HttpMsgService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
