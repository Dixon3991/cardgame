import { Card } from './card';

export class CardDeck {
    success: boolean;
    deck_id: string;
    cards?: Card[];
    shuffled?: boolean;
    remaining?: number;

};

export class CardDraw {

};