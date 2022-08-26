import { TestBed } from '@angular/core/testing';

import { DeckOfCardsService } from './deck-of-cards.service';

describe('DeckOfCardsService', () => {
  let service: DeckOfCardsService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(DeckOfCardsService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
