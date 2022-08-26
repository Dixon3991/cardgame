import { TestBed } from '@angular/core/testing';

import { CardImageService } from './card-image.service';

describe('CardImageService', () => {
  let service: CardImageService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(CardImageService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
